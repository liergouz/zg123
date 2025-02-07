
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0511);
        set_name( "医术" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "05111"->can_perform(me);
        __DIR__ "05112"->can_perform(me);
        __DIR__ "05115"->can_perform(me);
        __DIR__ "05114"->can_perform(me);
        __DIR__ "05113"->can_perform(me);
        __DIR__ "05116"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 05111 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05112 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05113 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05114 );
}

// 函数：重计属性
void recount_char( object me ) 
{ 
        USER_ENERGY_D->count_max_mp(me);
        USER_ENERGY_D->count_pp(me);   
}

// 函数：获取描述
string get_desc() 
{
        return "［医术］提升云梦泽的最大法术力，每级提升3点。提升法术防御力，每级提升0.9点。\n";
}
