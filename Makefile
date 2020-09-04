.PHONY: clean All

All:
	@echo "----------Building project:[ htn_planner - Debug ]----------"
	@cd "htn_planner" && "$(MAKE)" -f  "htn_planner.mk"
clean:
	@echo "----------Cleaning project:[ htn_planner - Debug ]----------"
	@cd "htn_planner" && "$(MAKE)" -f  "htn_planner.mk" clean
