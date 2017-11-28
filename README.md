# User Control System - TP1


### Sistema de controle de Usuário

> O objetivo principal deste sistema é criar uma aplicação de controle de usuário e reservas de sala com OpenCV,para o reconhecimento de face do usuário, Qt5 Framework para a interface e banco de dados em json para armazenar os dados pertinentes.

### Requisitos

> Para realizar o build do sistema é necessário possuir o OpenCV da última versão instalado e o Qt5 Framework.

- O projeto é feito em C++ compilando no GCC 5.4.0
- OpenCv 3:
- Qt5 (5.10.o)

# OpenCV 3

> Siga este [Tutorial](https://www.learnopencv.com/install-opencv3-on-ubuntu/) (pule os passo 3,5.4 e 6 em diante)
> Após instalado mude o diretório setado no atributo face_cascade_name da classe CamInterface, para o correspondente da sua instalação do passo anterior.

# Qt5 Framework (gui)
> [Download Qt 5.10.0 beta linux](http://download.qt.io/official_releases/online_installers/qt-unified-linux-x64-online.run) > Após o download e a instalação, mude no CMakeLists.txt as seguintes linhas, para o correspondente da instalação feita:

```txt
set(Qt5Core_DIR /opt/Qt/5.10.0/gcc_64/lib/cmake/Qt5Core)
set(Qt5Widgets_DIR /opt/Qt/5.10.0/gcc_64/lib/cmake/Qt5Widgets)
```

# Build e Compilation

> Após feito todos os passos de instalação das dependências, basta fazer o build com cmake:

```sh
$ cmake CMakeLists.txt
$ make
```

> Caso dê algum erro no build, provavelmente as dependências não foram instaladas corretamentes ou setadas!


> E finalmente inicie a aplicação:

```sh
$./control-system
```

# Telas do Sistema

## Tela principal de acesso:
![|acesso](https://gitlab.com/lksalbq/user-control-system/raw/master/user-control-system-screenshots/acesso.png)

## Tela de cadastro de usuários:
![|cadastro_usuario](https://gitlab.com/lksalbq/user-control-system/raw/master/user-control-system-screenshots/cadastro_usuario.png)

## Tela de reservas:
![|reservas](https://gitlab.com/lksalbq/user-control-system/raw/master/user-control-system-screenshots/reservas.png)

## Tela de cadastro de reservas:
![|cadastro_reservas](https://gitlab.com/lksalbq/user-control-system/raw/master/user-control-system-screenshots/cadastro_reservas.png)

# Documentação
> Os diagramas de classe foram gerados a partir do [Doxygen](http://www.stack.nl/~dimitri/doxygen/) e podem ser acessados clicando [AQUI](https://gitlab.com/lksalbq/user-control-system/raw/master/doc/index.html) (o gitlab não permite a visualização direta de páginas html, então é necessário clonar o repositório e acessar localmente)


# Diagramas de sequência

## Cadastro de Usuário

![|create user](https://gitlab.com/lksalbq/user-control-system/raw/master/sequence_diagram/create_user.png)

## Identificação de Usuário

![| identify user](https://gitlab.com/lksalbq/user-control-system/raw/master/sequence_diagram/identify_user.png)










