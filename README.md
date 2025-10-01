Hash generatorius
Atliko Marius Augustinas 1 gr. 1 pogr.

Hash veikimas:
1. Įvedimas yra string formoje.
2. Daroma kopija, o originalo simboliai sumaišomi naudojant atsitiktinių skaičių generatorių.
3. Atliekamos abiejų string vienodų elementų sumos, sandaugos, bitų XOR, bitų AND skaičiavimai.
4. Sukuriamas 32 bitų ilgio masyvas su 32 elementais ir sugeneruojami atsitiktiniai skaičiai.
5. Pereinami visi input elementai (i) ir jie pridedami prie 32 bitų masyvo elemento (i % 32).
6. 32 bitai po vieną atitinkamai paverčiami į dviejų šešioliktainės sistemos simbolių skaičių.

Eksperimentinis tyrimas:

Vieno simbolio failai:
a.txt 1-as bandymas - Hash: 1ad1352912caa4c1423f6c8494c154c77283df5778c54080d2789a1ec4774a6c
a.txt 2-as bandymas - Hash: 1ad1352912caa4c1423f6c8494c154c77283df5778c54080d2789a1ec4774a6c
b.txt 1-as bandymas - Hash: 2d8ca58f8bbf286fbdc4812db2b947a89dfa01cc739ebf11ebdcd525b9a4cd86
b.txt 2-as bandymas - Hash: 2d8ca58f8bbf286fbdc4812db2b947a89dfa01cc739ebf11ebdcd525b9a4cd86
c.txt 1-as bandymas - Hash: ed475611bfa36197ba22f5bcb8f04b2d79fe6da288ede2aea3368492b90fee14
c.txt 2-as bandymas - Hash: ed475611bfa36197ba22f5bcb8f04b2d79fe6da288ede2aea3368492b90fee14
Išvedimo dydis vienodas ir yra deterministiškumas.

Failai su daug simbolių 1500:
daug.txt 1-as bandymas - Hash: 52c806dd5f8f89a174d8c6c6ab88e2da8fdadfa5cecc9b2e42592dbe49d513c2
daug.txt 2-as bandymas - Hash: 52c806dd5f8f89a174d8c6c6ab88e2da8fdadfa5cecc9b2e42592dbe49d513c2
daug2.txt 1-as bandymas - Hash: 21d00a796cfb5172836798c552f30835631f5095ce5775f78d653169b9e4216e
daug2.txt 2-as bandymas - Hash: 21d00a796cfb5172836798c552f30835631f5095ce5775f78d653169b9e4216e
Išvedimo dydis vienodas ir yra deterministiškumas.

Failai su daug simbolių 1500 ir vienu pakeistu simboliu viduryje:
daug.txt 1-as bandymas - Hash: 52c806dd5f8f89a174d8c6c6ab88e2da8fdadfa5cecc9b2e42592dbe49d513c2
daug.txt 2-as bandymas - Hash: 52c806dd5f8f89a174d8c6c6ab88e2da8fdadfa5cecc9b2e42592dbe49d513c2
daugp.txt 1-as bandymas - Hash: 52c806dd5f8f89a174d8c6c6ab88e2da8fdadfa5cecc9b2e42592dbe49d513c2
daugp.txt 2-as bandymas - Hash: 52c806dd5f8f89a174d8c6c6ab88e2da8fdadfa5cecc9b2e42592dbe49d513c2
daug2.txt 1-as bandymas - Hash: 21d00a796cfb5172836798c552f30835631f5095ce5775f78d653169b9e4216e
daug2.txt 2-as bandymas - Hash: 21d00a796cfb5172836798c552f30835631f5095ce5775f78d653169b9e4216e
daug2p.txt 1-as bandymas - Hash: 21d00a796cfb5172836798c552f30835631f5095ce5775f78d653169b9e4216e
daug2p.txt 2-as bandymas - Hash: 21d00a796cfb5172836798c552f30835631f5095ce5775f78d653169b9e4216e
Išvedimo dydis vienodas ir yra deterministiškumas, yra kolizija.

Tuščias failas:
tuscias.txt 1-as bandymas - Hash: d974e7e6dfac02d6006fe574aaa06f89bb2be1cc86bf2e1217ac668c18604a97
tuscias.txt 2-as bandymas - Hash: d974e7e6dfac02d6006fe574aaa06f89bb2be1cc86bf2e1217ac668c18604a97

konstitucija.txt:
Skaičiavimo laikas:
1 eilutė: 0.1284 ms
2 eilutės: 0.14636 ms
4 eilutės: 0.14006 ms
8 eilutės: 0.1502 ms
16 eilučių: 0.15024 ms
32 eilutės: 0.1417 ms
64 eilutės: 0.13722 ms
128 eilutės: 0.14192 ms
256 eilutės: 0.14706 ms
512 eilučių: 0.15218 ms

Kolizijos:
10 simbolių: No collisions found in 100000 hashes.
100 simbolių: No collisions found in 100000 hashes.
1000 simbolių: No collisions found in 100000 hashes.

Lavinos efektas:
Poru skaicius: 100000

=== Bitų lygmuo (256 bit hash) ===
Minimalus skirtumas: 95 bitai
Maksimalus skirtumas: 161 bitai
Vidutinis skirtumas: 49.997773 %

=== Hex simbolių lygmuo (64 hex simboliai) ===
Minimalus skirtumas: 49 simboliai
Maksimalus skirtumas: 64 simboliai
Vidutinis skirtumas: 93.748406 %

Negrįžtamumo demonstracija:
Rezultatas (proof-of-work):
Rasta: TAIP
Rastas nonce/salt: "239"
Hash: 000b07a0554de22446fe8243a22095b2f9c2558865fcf74287b07aed547a7801
Bandymu skaičius: 240
Laikas: 11.548 ms

Išvados:
Eksperimento metu nustatyta, kad hash yra deterministiškas, visada gražina 64 hex simbolius. Pastebėta, kad maži dideliuose failuose esasntys pakeitimai gražina tą pačią reikšmę. Hash skaičiavimo laiko priklausomybė nuo įvesties ilgio nepastebėta.
