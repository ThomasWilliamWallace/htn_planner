.PHONY: clean All

All:
	@echo "----------Building project:[ hardtime_textworld - Debug ]----------"
	@cd "hardtime_textworld" && "$(MAKE)" -f  "hardtime_textworld.mk"
clean:
	@echo "----------Cleaning project:[ hardtime_textworld - Debug ]----------"
	@cd "hardtime_textworld" && "$(MAKE)" -f  "hardtime_textworld.mk" clean
