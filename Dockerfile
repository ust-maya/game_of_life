FROM alpine:latest
RUN apk add --no-cache gcc make libc-dev ncurses-dev bash
WORKDIR /app
COPY . .
RUN make
CMD ["./game_of_life"]