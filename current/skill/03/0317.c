
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0317);
        set_name( "护体金罡" );
}

// 函数：能否特殊技
void can_perform( object me )
{
//        __DIR__ "03171"->can_perform(me);
        __DIR__ "03172"->can_perform(me);
        __DIR__ "03173"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
//        send_user( me, "%c%w%w", 0x50, 0xffff, 03171 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03172 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03173 );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_hurt(me); }

// 函数：获取描述
string get_desc() 
{
        return "［护体金罡］可以通过不断地战斗生成“元气”；技能等级高时能自动反弹敌人的物理伤害\n";
}
