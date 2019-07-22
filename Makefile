CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Werror=vla -MMD -g

OBJECTS=main.o Chamber.o Floor.o Position.o Tile.o getTile.o bg/Stair.o bg/Barrier.o bg/Doorway.o bg/FloorTile.o bg/HorizontalWall.o bg/Passage.o bg/PlayerExclusive.o bg/TheVoid.o bg/VerticalWall.o characters/Character.o characters/npcs/Dragon.o characters/npcs/Dwarf.o characters/npcs/Elf.o characters/npcs/Halfling.o characters/npcs/Human.o characters/npcs/Merchant.o characters/npcs/NPC.o characters/npcs/Orc.o characters/players/Goblin.o characters/players/Player.o characters/players/Shade.o characters/players/Troll.o characters/players/Vampire.o items/Gold.o items/Item.o items/potions/Potion.o isDirection.o

DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

TESTDIR=.
EXECSDIR=../executables
EXECGIVEN=${EXEC}
SUITE=suiteq4.txt

${EXEC}: ${OBJECTS} 
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean


# @ silences output
test:
	@cp ${EXECSDIR}/${EXECGIVEN} ${TESTDIR}                 # copy over given exec
	@mv ${TESTDIR}/${EXECGIVEN} ${TESTDIR}/sol_${EXECGIVEN} # prefix it with sol_
	@cp ${EXEC} ${TESTDIR}                                  # copy over your exec
	@(cd ${TESTDIR}\									    # go into test directory
	&& ./produceOutputs ${SUITE} ./sol_${EXECGIVEN}\        # run produceOutputs
	&& ./runSuite ${SUITE} ./${EXEC})                       # run runSuite
.PHONY: test
