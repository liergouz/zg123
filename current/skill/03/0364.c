
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0364);
        set_name( "踏雪无痕" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "03641"->can_perform(me);
        __DIR__ "03642"->can_perform(me);
        __DIR__ "03643"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 03641 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03642 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03643 );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_sp(me); }

// 函数：获取描述
string get_desc() 
{
        return "［踏雪无痕］提升躲闪，每级提升 3 点\n";
}
