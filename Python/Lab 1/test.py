def func(min, max):
    if type(min) != int or type(max) !=int:
        raise TypeError("The min and max must be of type int")
    if min > max:
        raise ValueError("The min must not be bigger then the max")
    return max-min


def main():
    #trying to create a function (the difference between two numbers)
    try:
        print("The result of func(): ", func())
    except NameError:
        print("Cannot find the function")
    except TypeError:
        print("Missing one of the arguments")
    except SyntaxError:
        print("Other issues")

    try:
        print("The result of func(10): ", func())
    except TypeError:
        print("Missing one of the arguments :")

    try:
        print("The result of func(20,10): ", func(20,10))
    except ValueError as err_msg:
        print("The result of func(20,10): ", err_msg)
              
    try:
        print("The result of func(10,20):", func(10,20))
    except ValueError as err_msg:
        print("The result of func(10,20): expected:=10", err_msg)

    
main()
