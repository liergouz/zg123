#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(650);
	set_skill_type(2);
	set_number(712);
	set_name("神威项链制作");
	set_skill_level(96);
	set_tool(517);
	set_tili(4);
	set_final("/item/final/86/8096");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(2);
	set_base_rate(65);
        set_product( ([
	"64"	: 	2, 
	"43"	: 	3, 
	"103"	: 	3, 
	"86"	: 	2, 
	"323"	: 	4, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
