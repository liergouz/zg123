
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0425);
        set_name( "乾坤挪移" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "04252"->can_perform(me);
        __DIR__ "04253"->can_perform(me);
        __DIR__ "04254"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04252 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04253 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04254 );
}

// 函数：获取描述
string get_desc() 
{
        return "［乾坤挪移］提升法术防御力，每级提升 1 点。\n";
}
