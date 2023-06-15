# FastestPathMatrix
Version of a Fastest path in matrix asked in a google interview

Data je matrica 𝑚 × 𝑛. Na početku se nalazimo u polju (0,0), a cilj je doći u polje (0, 𝑛 − 1). Ako se 
nalazimo u polju (𝑖,𝑗), u jednom potezu je dozvoljeno ići u bilo koje od polja (𝑖 − 1,𝑗 + 1), (𝑖,𝑗 +
1), (𝑖 + 1,𝑗 + 1).
<ul>
  <li>Odrediti broj načina da se na opisani način dođe od početka do kraja;</li>
  
  <li>Neka polja matrice su zabranjena (recimo data je bool matrica istih dimenzija koja određuje 
  koja polja su zabranjena). Odrediti u ovom slučaju broj načina da se dođe od početka do kraja.</li>
  
  <li>Dat je niz različitih indeksa 𝑖1,𝑖2, … , 𝑖𝑘 (𝑘 ≤ 𝑚) (koji ne mora biti sortiran). Potrebno je 
  odrediti broj načina da se dođe od početka do kraja tako da postoji potez u kojem se nalazimo 
  u redu 𝑖1, pa poslije njega potez u kojem se nalazimo u redu 𝑖2, pa poslije njega potez u kojem 
  se nalazimo u redu 𝑖3, i tako dalje. Prodiskutovati optimalno rješenje (po vašem mišljenju) sa 
  aspekta vremenske složenosti u odnosu na optimalno rješenje sa aspekta memorijske 
    složenosti.</li>
</ul>
