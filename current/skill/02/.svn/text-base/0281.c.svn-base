
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0281);
        set_name( "御风心法" );
}

// 函数：能否特殊技
void can_perform( object me )
{
	me->set_attack_move(1);
        __DIR__ "02811"->can_perform(me);
        __DIR__ "02812"->can_perform(me);
        __DIR__ "02813"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 02811 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02812 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02813 );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_cp(me); }

// 函数：获取描述
string get_desc() 
{
        return "［御风心法］能驾驭风的法术技能。\n";
}
