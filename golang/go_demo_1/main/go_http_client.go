package main

import (
	"bufio"
	"fmt"
	"io"
	"net/http"
)

//Go 标准库的 net/http 包为 HTTP 客户端和服务端提供了出色的支持。
//在这个例子中，我们将使用它发送简单的 HTTP 请求。
func main() {
	resp, err := http.Get("https://www.google.com")
	if err != nil {
		panic(err)
	}
	defer func(Body io.ReadCloser) {
		err := Body.Close()
		if err != nil {
			panic(err)
		}
	}(resp.Body)
	fmt.Println("Response status:", resp.Status)
	scanner := bufio.NewScanner(resp.Body)
	for i := 0; scanner.Scan() && i < 5; i++ {
		fmt.Println(scanner.Text())
	}
	if err := scanner.Err(); err != nil {
		panic(err)
	}
}
