#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(640);
	set_skill_type(2);
	set_number(519);
	set_name("���ɹ�����");
	set_skill_level(45);
	set_tool(511);
	set_tili(1);
	set_final("/item/final/65/6045");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"50"	: 	4, 
	"40"	: 	1, 
	"215"	: 	1, 
	"312"	: 	1, 
//	��	: 	0, 
//	��	: 	0,       	     
        ])); 	
        set_count(1);
}
