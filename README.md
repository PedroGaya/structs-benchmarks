# O projeto

Olá! Eu escrevi esse simples MD para orientar qualquer um que queira navegar o projeto.

Ele foi feito como trabalho final para a minha cadeira de Estrutura de Dados, na UFRGS. Você pode usar o projeto pro que quiser, como quiser. Nem precisa me citar.

O propósito desse trabalho era comparar, quantitativamente, duas estruturas de dados. Eu escolhi a ABP e a LSEC devido as diferentes combinações de complexidade temporal que elas gerariam. Outras árvores (em especial, as auto-balanceadas) são O(log n) em tudo. Sem graça, na minha opinião.

Além do descrito aqui, as funções e tipos estão anotados com comentários no código fonte.

Por fim, esse projeto foi feito em Windows 10, mas creio eu que todas as soluções funcionam tanto em Linux como Windows. Não testei, pois minha instalação de Arch se recusa a funcionar direito.

## "Instalação"

1. Instale [CMake](https://cmake.org/install/) e um [compilador](https://bellard.org/tcc/).
2. Rode esses comandos no local de instalação:

```
mkdir TrabalhoFinal && cd TrabalhoFinal
git clone https://github.com/PedroGaya/structs-benchmarks.git .
cmake .
```

3. O executável está em `./build`, então:
   `cd build && trabFinal -r -s 1000`

Isso criará um banco de dados com 1000 números aleatórios e rodará as benchmarks. Use a opção `-c` para deletar todos os bancos de dados previamente gerados, antes de gerar novos.

IMPORTANTE: Seguir esses passos a risca provavelmente criará erros devido a configurações do CMake. Recomendo fortemente simplesmente clonar apenas src e o arquivo CMakeLists.txt clicando [aqui](https://github.com/PedroGaya/structs-benchmarks-src).

## Arquivos e pastas

O projeto possui 4 pastas principais, `build/`, `logs/`, `plots/` e `src/`, descritas abaixo. Além disso, possui um arquivo CMake e dados do VSCode.

Para compilar na marra, você precisa criar a pasta `logs/` a mão, pois `fopen()` não criará os diretórios necessários.

### build/

Essa pasta contém os arquivos de build usados pelo CMake. Verbose é usado. O executável `trabFinal.exe` está nessa pasta.

### logs/

Aqui são guardados todos os arquivos de texto usados como """""bancos de dados""""". Na prática, são dados mau-formatados jogados em um arquivo. A estrutura dessa pasta é importante e case sensitive, mas os arquivos dentro dela são irrelevantes e podem ser apagados.

### plots/

Contém dois scripts de Python, usados para gerar os gráficos no relatório, além de todas as imagens geradas por eles. Ambos geram os gráficos automaticamente, mas os dados precisam ser manipulados manualmente dentro deles para os alterar.

### src/

Contém todo o código fonte do projeto, incluindo as implementações das estruturas, a geração de dados e a CLI. O ponto de começo do programa é o arquivo `main.c`.

O projeto usa diversas bibliotecas open source. Uma delas está em `./mtwister` e a outra em `./log`

As estruturas de dados e todas as suas funções estão na pasta `./models`

## Créditos

Agradeço a minha professora por passar esse trabalho; Ele foi desafiador e divertido do começo ao fim. Aprendi muito com ele.

O projeto foi feito só por mim, Pedro Gaya.
