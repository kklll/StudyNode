package main

import "fmt"

func main() {
	message := make(chan string, 2)
	message <- "我的第一个消息"
	message <- "我的第二个消息"
	fmt.Println(<-message)
	fmt.Println(<-message)
}
