#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(620);
	set_skill_type(1);
	set_number(93);
	set_name("쫷�ȭ�׶���");
	set_skill_level(98);
	set_tool(502);
	set_tili(1);
	set_final("/item/final/70/1090");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"262"	: 	3, 
	"41"	: 	1, 
	"241"	: 	1, 
	"320"	: 	1, 
//	��	: 	0,       	     
//	��	: 	0,    
        ])); 	
        set_count(1);
}
