package main

import "fmt"

func main() {
	//定义一个channel
	message := make(chan string)
	go func() {
		//在协程中给通道发送一个消息
		message <- "ping"
	}()
	//从通道中读取消息
	//默认发送和接收操作是阻塞的，直到发送方和接收方都就绪。 这个特性允许我们，不使用任何其它的同步操作， 就可以在程序结尾处等待消息 "ping"。
	msg := <-message
	fmt.Println(msg)
}
