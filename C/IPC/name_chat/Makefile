all: talkA talkB

read: talkA.c
	gcc $< -o $@

write: talkB.c
	gcc $< -o $@

.PHONY:clean
clean:
	rm -rf talkA talkB
