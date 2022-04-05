import random
import sys

LINES = int(sys.argv[2])
FILENAME = sys.argv[1]
NUMS = 500

MIN = 1
MAX = 1000


def dataproduct()->None:
    """product a group of data,write into file"""

    a = []
    i = 0
    while i < NUMS:
        dataele = random.randint(MIN,MAX)
        a.append(dataele)
        i+=1
    b = sorted(a)

    with open(FILENAME,"a") as fileobj:
        # general and write a group of data
        datastr = " ".join([str(x) for x in a]) + '\n'
        datastr += " ".join([str(x) for x in b]) + "\n\n"
        fileobj.write(datastr)



if __name__ == '__main__':
    i = 0
    while i < LINES:
        dataproduct()
        i+=1

