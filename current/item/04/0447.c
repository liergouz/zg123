
// �Զ����ɣ�/make/item/make30

inherit ITEM;
inherit COMBINED;
// ��������������
int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("�ݹ���Ŵ��");
        set_picid_1(3204);
        set_picid_2(3204);
        set_value(50);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�ü��ݺã����������õ�Ŵ��"; 
}

void reset()
{
        if( gone_time( get_drop_time() ) > 2400 )    // 40����
        {
                remove_from_scene();
                destruct( this_object() );
        }
}