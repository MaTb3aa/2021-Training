const int N = 1e7;
bool seive[N];
vector<int>primes;
oid generate() {
	memset(sieve, 1, sizeof sieve);
	sieve[0] = sieve[1] = 0;
	for (int i = 4; i < N; i += 2)
		sieve[i] = 0;
	for (int i = 3; i * i < N; i += 2) {
		if (!sieve[i])
			continue;
		for (int j = i * i; j < N; j += i + i)
			sieve[j] = 0; 
	}
	primes.push_back(2);
	for (int i = 3; i < N; i += 2)
		if (sieve[i]) primes.push_back(i);
}
