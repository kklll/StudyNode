package main

import (
	"fmt"
	"math/rand"
	"sync/atomic"
	"time"
)

type readOps struct {
	key  int
	resp chan int
}
type writeOps struct {
	key   int
	value int
	resp  chan bool
}

func main() {
	var readCount uint64 = 0
	var writeCount uint64 = 0
	reads := make(chan readOps)
	writes := make(chan writeOps)
	go func() {
		var state = make(map[int]int)
		for {
			select {
			case read := <-reads:
				read.resp <- state[read.key]
			case write := <-writes:
				state[write.key] = write.value
				write.resp <- true
			}
		}
	}()
	for i := 0; i < 100; i++ {
		go func() {
			for {
				read := readOps{
					key:  rand.Intn(5),
					resp: make(chan int),
				}
				reads <- read
				<-read.resp
				atomic.AddUint64(&readCount, 1)
				time.Sleep(time.Millisecond)
			}
		}()
	}

	for i := 0; i < 10; i++ {
		go func() {
			for true {
				write := writeOps{
					key:   rand.Intn(5),
					value: rand.Intn(100),
					resp:  make(chan bool),
				}
				writes <- write
				<-write.resp
				atomic.AddUint64(&writeCount, 1)
				time.Sleep(time.Millisecond)
			}
		}()
	}
	time.Sleep(time.Second)
	finalr := atomic.LoadUint64(&readCount)
	fmt.Println("final readCount", finalr)
	finalw := atomic.LoadUint64(&writeCount)
	fmt.Println("final writeCount", finalw)
}
