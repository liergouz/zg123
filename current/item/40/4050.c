
// �Զ����ɣ�/make/item/make30

inherit ITEM;
    inherit COMBINED;

// ������ԭ������
int get_stuff_type() { return 237; }

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(4050);
        set_picid_2(4050);
        set_value(290);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һ���������ά"; 
}
