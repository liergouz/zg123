inherit COPY_MAP;

// ���������촦��
void create() 
{ 
        object me = this_object();

        set_client_id(704);
        set_name("�ܼ๤�鷿");

        if( !clonep(me) ) return;

        set_heart_timer( me, set_heart_timer_2(me, getoid(me) % 10) );    // �������
        set_heart_loop(me, 600);    // ѭ��������������
        me->heart_beat();
        set_heart_beat(1);
}
