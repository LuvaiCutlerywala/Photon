# Syntax for Photon
Photon is a language inspired by simplicity, therefore, the motivation is to include the minimal
amount of syntactic sugar as possible. Of course, some things are repeated often enough to
warrant having to make a shorter way to do it, but this is not the case for every example. There
are many cases in which, due to the mess of the syntactic sugar, the underlying logic becomes 
unnecessarily hard to read. Photon is designed to avoid this problem, no matter how arduous the
programmer might find having to move their finger a few inches and press on a key. 

## Syntactic Breakdown
The entire program is expressed as a set of statements, each composed of expressions, which
combine, through some logical operations, terms and factors that produce some output. The
following are the definitions used for the development of the compiler for this language.

- **Statement**: Any combination of expressions, which would be combined using the intersection 
or union of the sets that the operation is defined over. The intersection or union, expressed as
logical addition or multiplication, are the only operations which can be used to compose the
group that is formed by equipping the set of all inputs with the logical addition and multiplication.

TODO: Complete this.