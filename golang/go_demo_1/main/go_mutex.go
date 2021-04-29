package main

import (
	"fmt"
	"math/rand"
	"sync"
	"sync/atomic"
	"time"
)

func main() {
	//状态
	var state = make(map[int]int)
	//互斥锁
	var mutex = &sync.Mutex{}
	var readOps uint64
	var writeOps uint64
	for r := 0; r < 100; r++ {
		go func() {
			total := 0
			for {
				key := rand.Intn(5)
				mutex.Lock()
				total += state[key]
				mutex.Unlock()
				atomic.AddUint64(&readOps, 1)
				time.Sleep(time.Millisecond)
			}
		}()
	}

	for w := 0; w < 10; w++ {
		go func() {
			key := rand.Intn(5)
			value := rand.Intn(100)
			mutex.Lock()
			state[key] = value
			mutex.Unlock()
			atomic.AddUint64(&writeOps, 1)
			time.Sleep(time.Millisecond)
		}()
	}
	time.Sleep(time.Second)
	finalReadOps := atomic.LoadUint64(&readOps)
	fmt.Println("final read ops:", finalReadOps)
	finalWriteOps := atomic.LoadUint64(&writeOps)
	fmt.Println("final write ops:", finalWriteOps)
	mutex.Lock()
	fmt.Println("state", state)
	mutex.Unlock()
}
