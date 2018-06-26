import pybindings

# Use the add function
print("1 + 2 = {}".format(pybindings.add(1, 2)))

# Use the adder class
adder = pybindings.Adder(3)
print("3 + 2 = {}".format(adder.add(2)))
adder.addition = 4
print("4 + 3 = {}".format(adder.add(2)))

# Use the join function that uses the stl
print("join(['a', 'b', 'c']) = {}".format(pybindings.join(['a', 'b', 'c'])))
