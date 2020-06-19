import TestModule
for value in range(-2147483647, 2147483647):
    if TestModule.TestMethod(True, value) != value:
        print ("error")
    if TestModule.TestMethod(False, value) != value:
        print ("error")
