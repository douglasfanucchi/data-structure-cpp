FROM alpine:latest

RUN apk --no-cache add make gcc g++ musl-dev binutils autoconf automake libtool pkgconfig check-dev file patch valgrind

COPY . .

ENTRYPOINT ["make", "unit"]
