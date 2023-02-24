import itertools
import random

def random_gen(low, high):
    while True:
        yield random.randrange(low, high)

gen = random_gen(-1024,1023)
items = list(itertools.islice(gen, 50000))

import numpy

# Creating an array
Array = numpy.array(items)

# Saving the array in a text file
numpy.savetxt("input_samples_50k.txt", Array)
