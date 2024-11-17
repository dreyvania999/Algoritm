def factorial(n) :
    f = n
    for i in range(1, n) :
        f = f * i
        return f

        inputln = int(input())
        print(factorial(inputln))