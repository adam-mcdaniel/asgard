from functools import reduce
from subprocess import check_call, STDOUT, DEVNULL, call
from sys import argv
from os import system
from glob import glob
from os.path import isfile, dirname
from options import DATA_FILE_DIR, ASGARD_PATH, USE_OLD_DATA, LEVELS, DEGREES


# Convert bytes to megabytes
def bytes_to_megabytes(b): return int(b) / 10**6


# Runs gperf on the commandline to generate output files for profiling
def run_gperf(level, degree, pde, gperf_output, asgard_output):
    # check_call(
    #     f"{ASGARD_PATH} -p {pde} -l {level} -d {degree} > {asgard_output}")

    with open(f'{asgard_output}', 'w') as output_file:
        try:
            check_call([
                f'{ASGARD_PATH}',
                '-l', f'{level}',
                '-d', f'{degree}',
                '-p', f'{pde}'
            ], stdout=output_file, stderr=output_file, shell=True, env={'HEAPPROFILE': 'asgard.hprof'})
            output_file.close()
        except:
            pass

    with open(f"{glob('asgard.hprof.*')[-1]}", 'r') as f:
        content = f.read()
        f.close()
    with open(f"{gperf_output}", 'w') as f:
        content = f.write(content)
        f.close()

    for hprof in glob('asgard.hprof.*'):
        system(f"rm {hprof}")


# Gets the workspace mem usage and total mem usage for asgard
def get_mem_usage(level, degree, pde):
    # The extension added to the massif and asgard output files
    output_file_extention = f".out.l{level}_d{degree}_p{pde}"

    gperf_output = DATA_FILE_DIR + "/gperf" + output_file_extention
    asgard_output = DATA_FILE_DIR + "/asgard" + output_file_extention

    # Call valgrind on asgard with specified level, degree, and pde
    # Write output to asgard_output
    if not USE_OLD_DATA or not isfile(gperf_output):
        run_gperf(level, degree, pde, gperf_output, asgard_output)

    # Parse the output files
    total_mem_usage = GPerfReader(gperf_output).get_peak()

    # A struct containing the workspace and total mem usage for asgard
    return total_mem_usage


# Used to read the gperf output file from running asgard
class GPerfReader:
    def __init__(self, filename=None):
        self.filename = filename
        if filename:
            self.open(filename)

    # Open a massif output file
    def open(self, filename):
        self.filename = filename
        self.lines = open(filename, 'r').readlines()

    # Get the peak memory usage from the opened massif output file
    def get_peak(self):
        if len(self.lines) > 0:
            line = self.lines[0]
            return int(bytes_to_megabytes(line.split(']')[0].split(':')[-1].strip()))
        raise Exception(
            f"No peak found in gperf output file '{self.filename}'")
