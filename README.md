# Desafio - Control id
## Instruções de compilação
### Compilando e executando no próprio Host

A primeira opção de execução do programa é usar a própria máquina host. Para isso, siga os seguintes passos:

 - Instalar as dependências:

    \# apt-get install automake autoconf libtool

 - Realizar os passos a seguir para compilação:

    $ ./autogen.sh && ./configure && make

O binário **postprinter** será gerado no mesmo diretório e pode ser executado seguindo as seguintes regras:

- Pode receber um ou nenhum parâmetro na sua execução;
-   Se não receber nenhum parâmetro, baixa a partir do [site](https://jsonplaceholder.typicode.com/) os _users_ (/users) e imprime todos de maneira formatada no shell;
-   Se receber um parâmetro, carrega do mesmo site os _posts_ do usuário cujo id é o argumento fornecido e, em seguida, imprimir os _posts_ de maneira formatada no shell;

### Adicionando o pacote a um recipe yocto
O diretório **meta-controlid** contém uma layer que pode ser adicionada a uma instalação existente do yocto para adicionar o programa a uma imagem linux. Para isso, basta adicionar o diretório meta-controlid à raiz do poky e editar o arquivo bblayers.conf para adicionar a nova layer ao seu build, segue um exemplo:

>   BBLAYERS ?= " \\
>    /path/to/yocto/meta \\
>    /path/to/yocto/meta-yocto \\
>    /path/to/yocto/meta-yocto-bsp \\
>    /path/to/yocto/meta-controlid \\
>    "

Observe que uma das dependências do pacote postprinter é a lib jsoncpp, que pode ser achado na camada meta-oe da open embedded. Caso essa camada não esteja presente no build atual, é necessário adicioná-la usando o mesmo processo.
### Testando o pacote em um build yocto
Depois de feito o passo a passo acima, basta executar o build para a plataforma target escolhida e o **postprinter** já estará adicionado ao rootfs gerado. O binário estará em /usr/bin/postprinter e apresenta o mesmo comportamento explicado anteriormente.