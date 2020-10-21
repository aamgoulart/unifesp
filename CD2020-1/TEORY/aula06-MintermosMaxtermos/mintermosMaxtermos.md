# Mintermos e Maxtermos

## Mintermos 

Técnica baseada nos valores de saída que são
iguais a 1.

1. Criar um mintermo para cada linha com saída 1
2. O mintermo é um AND de todas as entradas
- Entradas com valor 0 aparecem negadas
- Entradas com valor 1 aparecem não negadas
3. Fazer um OR entre todos os mintermos

*Geram circuitos AND-OR* e pode ser reduzidos a NAND-NAND

## Maxtermos

Técnica baseada nos valores de saída que são
iguais a 0.

1. Criar um mintermo para cada linha com saída 0
2. O mintermo é um OR de todas as entradas
- Entradas com valor 1 aparecem negadas
- Entradas com valor 0 aparecem não negadas
3. Fazer um AND entre todos os mintermos

*Geram circuitos OR-AND* e pode ser reduzidos a NOR-NOR