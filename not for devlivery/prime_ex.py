

def is_prime(x):
    if x <= 1:
        return False
    for i in range(2, x):
        if x%i == 0:
            return False
    return True

primes = []
for i in range(1,50):
    if is_prime(i):
        primes
