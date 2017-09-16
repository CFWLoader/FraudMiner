#!/bin/sh

for((idx = 1; idx <= 10; ++idx)); do
	python3 ./TcpClient.py &
done
