
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0422);
        set_name( "阴阳五行" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "04221"->can_perform(me);
        __DIR__ "04222"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04221 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04222 );
}

// 函数：重计属性
void recount_char( object me ) 
{ 
        USER_ENERGY_D->count_cp(me); 
}

// 函数：获取描述
string get_desc() 
{
        return "［阴阳五行］提升法术攻击力，每级提升 2 点。\n";
}
