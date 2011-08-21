#!/usr/bin/env python
import subprocess
import sys

BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE = range(8)

def format(fg=None, bg=None, bright=False, bold=False, dim=False, reset=False):
    # manually derived from http://en.wikipedia.org/wiki/ANSI_escape_code#Codes
    codes = []
    if reset: codes.append("0")
    else:
        if not fg is None: codes.append("3%d" % (fg))
        if not bg is None:
            if not bright: codes.append("4%d" % (bg))
            else: codes.append("10%d" % (bg))
        if bold: codes.append("1")
        elif dim: codes.append("2")
        else: codes.append("22")
    return "\033[%sm" % (";".join(codes))
    
passed = 0
failed = 0
skipped = 0
def accumulate(line):
    global passed, failed, skipped
    line = line.lstrip("Totals: ")
    parts = line.split(',')
    passed += int(parts[0].strip().split(' ')[0])
    failed += int(parts[1].strip().split(' ')[0])
    skipped += int(parts[2].strip().split(' ')[0])

def totals():
    if passed + failed + skipped == 0:
        return ""
    line = "-----------------------------------------------------------------\n"
    line += "Totals: passed: %s%s%s failed: %s%s%s skipped: %s%s%s" % \
    (format(fg=GREEN, bold=True), passed, format(reset=True),
    format(fg=RED, bold=True), failed, format(reset=True),
    format(fg=YELLOW, bold=True), skipped, format(reset=True)) 
    return line
    
def run_test():
    command = ['./test']
    if len(sys.argv) > 1:
        command.append(*sys.argv[1:])
    proc = subprocess.Popen(command, stdout=subprocess.PIPE)
    while True:
        line = proc.stdout.readline()
        if line.startswith('PASS'):
            line = line[line.find(':')+1:]
            print format(fg=GREEN, bold=True), '  PASS :', format(reset=True), line.strip()
        elif line.startswith('FAIL'):
            line = line[line.find(':')+1:]
            print format(fg=RED, bold=True), '  FAIL :', format(reset=True), line.strip()
        elif line.startswith('QFATAL'):
            line = line[line.find(':')+1:]
            print format(fg=BLACK, bg=RED), 'QFATAL :', format(reset=True), line.strip()
        elif line.startswith('QDEBUG'):
            print format(fg=BLACK, bold=True), line.strip(), format(reset=True)
        elif line.startswith("*********") or line.startswith("Config: Using QTest"):
            pass
        elif line.startswith("Totals:"):
            accumulate(line)
        elif line != '': 
            print line.strip()
        else:
            break
    total_line = totals()
    if total_line != '':
        print total_line
    print format(reset=True)

if __name__ == "__main__":
    run_test()