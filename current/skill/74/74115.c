// 部分自动生成：/make/skill/makeski74

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// 函数：宠物技能
int is_pet_skill() { return 1; }
// 函数：获取技能ID
int get_id() { return 74115; }
// 函数：获取技能类型
string get_name() { return "御法"; }
// 函数：获取技能类型（0、被动；1、主动）
int get_type() { return 0; }
// 函数：获取技能等级（0、普通；1、高级）
int get_level() { return 0; }
// 函数：获取描述
string get_desc( object me )
{
	return HIC+get_name()+"\n拥有此技能的宠物，将提高其当前法术攻击力的10%。";
}
// 函数：获取指令类型
int get_perform_type() { return 0; }

// 函数：能否使用指令
void can_perform( object me ,object pet)
{
        send_user( me, "%c%c%d%d%c%c%w%w%s", 0xA1,19,getoid(pet),get_id(),1, get_perform_type(), 1, 0, get_name() );
}
//技能的影响
void skill_effect(object pet,object owner)
{
	int point;
	if ( pet->get_skill(74206) )
		return ;
	point = pet->get_cp()/10;
	pet->set("sk74115",point);
	NPC_PET_D->count_cp(pet);
}
//删除技能的影响
void remove_skill_effect(object pet,object owner)
{
	int cp;
	cp = pet->get("sk74115");
	if ( cp )
	{
		pet->delete("sk74115");
		NPC_PET_D->count_cp(pet);
	}
}
