
// �Զ����ɣ�/make/item/make30

inherit ITEM;
inherit COMBINED;
// ��������������
int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("�кõ�����");
        set_picid_1(4218);
        set_picid_2(4218);
        set_value(50);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�кõģ����������õ�����"; 
}

void reset()
{
        if( gone_time( get_drop_time() ) > 2400 )    // 40����
        {
                remove_from_scene();
                destruct( this_object() );
        }
}