package main

import (
	"fmt"
	"time"
)

func f(from string) {
	for i := 0; i < 100; i++ {
		fmt.Println(from, ":", i)
	}
}

func main() {
	f("direct")
	go f("routine")

	go func(message string) {
		fmt.Println(message)
	}("我的消息")
	time.Sleep(time.Second)
	fmt.Println("done")
}
