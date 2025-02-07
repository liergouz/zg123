
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0421);
        set_name( "大乘道法" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "04211"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04211 );
}

// 函数：重计属性
void recount_char( object me ) 
{ 
        USER_ENERGY_D->count_max_mp(me); 
        USER_ENERGY_D->count_cp(me); 
}

// 函数：获取描述
string get_desc() 
{
        return "［大乘道法］提升法力上限，每级提升 4 点。提升法术攻击的爆击率，每级提升0.05％。\n";
}
