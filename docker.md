### Dockers学习


- Hello world  
```sh
docker run ubuntu:15.10 /bin/echo "Hello world"
```
- 运行交互式的容器  
我们通过docker的两个参数 -i -t，让docker运行的容器实现"对话"的能力
```sh
docker run -i -t ubuntu:18.04 /bin/bash
```

-t:在新容器内指定一个伪终端或终端。  
  
-i:允许你对容器内的标准输入 (STDIN) 进行交互。  

- 后台模式   
```sh
docker run -d ubuntu:18.04 /bin/sh -c "while true; do echo hello world; sleep 1; done"
```
我们需要确认容器有在运行，可以通过 docker ps 来查看

- 停止容器  
```sh
docker stop name
```
- 列出镜像列表  

我们可以使用 docker images 来列出本地主机上的镜像。

- REPOSITORY：表示镜像的仓库源 

- TAG：镜像的标签  

- IMAGE ID：镜像ID  

- CREATED：镜像创建时间  

- SIZE：镜像大小    

同一仓库源可以有多个 TAG，代表这个仓库源的不同个版本，如ubuntu仓库源里，有15.10、14.04等多个不同的版本，我们使用 REPOSITORY:TAG 来定义不同的镜像。


- 获取一个新的镜像  
当我们在本地主机上使用一个不存在的镜像时 Docker 就会自动下载这个镜像。如果我们想预先下载这个镜像，我们可以使用 docker pull 命令来下载它。
```sh
docker pull ubuntu:13.10
```

- 查找镜像  

```sh
docker search httpd
```
