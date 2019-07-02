from subprocess import Popen, PIPE
from functools import reduce
from subprocess import check_output, STDOUT, DEVNULL, call, check_call
from sys import argv
from os import remove
from glob import glob
from os.path import isfile, dirname
from options import DATA_FILE_DIR, ASGARD_PATH, USE_OLD_DATA, LEVELS, DEGREES


# Convert bytes to megabytes
def bytes_to_megabytes(b): return int(b) / 10**6


# Runs gperf on the commandline to generate output files for profiling
def run_gperf(level, degree, pde, gperf_output, asgard_output):
    with open(f'{asgard_output}', 'w') as output_file:
        try:
            check_call([
                f'{ASGARD_PATH}',
                '-l', f'{level}',
                '-d', f'{degree}',
                '-p', f'{pde}'
            ], stdout=output_file, stderr=output_file, shell=True, env={'HEAPPROFILE': 'asgard.hprof', 'HEAP_PROFILE_INUSE_INTERVAL': '1000'})
            output_file.close()
        except:
            pass

    name = glob('asgard.hprof.*')[-1]
    content = check_output([
        'google-pprof',
        '--show_bytes',
        f'{ASGARD_PATH}',
        name
    ], stderr=DEVNULL).decode('utf-8')

    mem = GPerfReader(content=content).get_peak()

    with open(f"{gperf_output}", 'w') as f:
        content = f.write(content)
        f.close()

    print("MAX", mem)
    return mem


# Gets the workspace mem usage and total mem usage for asgard
def get_mem_usage(level, degree, pde):
    # The extension added to the massif and asgard output files
    output_file_extention = f".out.l{level}_d{degree}_p{pde}"

    gperf_output = DATA_FILE_DIR + "gperf" + output_file_extention
    asgard_output = DATA_FILE_DIR + "asgard" + output_file_extention

    # Call valgrind on asgard with specified level, degree, and pde
    # Write output to asgard_output
    if not USE_OLD_DATA or not isfile(gperf_output):
        total_mem_usage = run_gperf(
            level, degree, pde, gperf_output, asgard_output)
    else:
        # Parse the existing output files
        total_mem_usage = GPerfReader(gperf_output).get_peak()

    # A struct containing the workspace and total mem usage for asgard
    return total_mem_usage


# Used to read the gperf output file from running asgard
class GPerfReader:
    def __init__(self, filename=None, content=""):
        self.filename = filename
        if filename:
            self.open(filename)
        elif content:
            self.lines = content.split('\n')

    # Open a gperf output file
    def open(self, filename):
        self.filename = filename
        self.lines = open(filename, 'r').readlines()

    # Get the peak memory usage from the opened gperf output file
    def get_peak(self):

        total = bytes_to_megabytes(float(list(filter(lambda t: "Total" in t, self.lines))[
            0].replace("Total: ", '').replace(' B', '')))

        return total

        raise Exception(
            f"No peak found in gperf output file '{self.filename}'")

    # # Get the peak memory usage from the opened gperf output file
    # def get_peak(self):
    #     total = 0
    #     if len(self.lines) > 0:
    #         for i, line in enumerate(self.lines[1:-10]):
    #             try:
    #                 current = bytes_to_megabytes(
    #                     int(line.split(']')[0].split(':')[-1].strip()))
    #                 # if current > maximum:
    #                 #     print(line, current)
    #                 #     maximum = current
    #                 total += current
    #             except:
    #                 pass
    #     # if maximum > 0:
    #     #     return maximum
    #     return total
    #     raise Exception(
    #         f"No peak found in gperf output file '{self.filename}'")
