v2 = 72
s = '' 
for encC in "[OIonU2_<__nK<Ks":
	for orgC in map(chr, xrange(33, 127)):
		if ord(encC) == (((ord(orgC) + 12) * v2 + 17) % 70 + 48):
			s += orgC
			v2 = ord(encC)
			break
print s