
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0261);
        set_name( "���컨��" );
}

// �������ܷ����⼼
void can_perform( object me )
{
	me->set_attack_move(1);
//        __DIR__ "02611"->can_perform(me);
        __DIR__ "02612"->can_perform(me);        
        __DIR__ "02614"->can_perform(me);
        __DIR__ "02615"->can_perform(me);
        __DIR__ "02616"->can_perform(me);
        __DIR__ "02617"->can_perform(me);
        __DIR__ "02613"->can_perform(me);
        __DIR__ "02618"->can_perform(me);
}

// ������ɾ�����⼼
void remove_perform( object me )
{
//        send_user( me, "%c%w%w", 0x50, 0xffff, 02611 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02612 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02613 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02614 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02615 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02616 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02617 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02618 );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_ap(me); }

// ��������ȡ����
string get_desc() 
{
        return "�����컨�������ʹ�ð����Ĺ�������ÿ������ 1.4 �㹥����\n";
}
