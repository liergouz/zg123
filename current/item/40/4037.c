
// �Զ����ɣ�/make/item/make30

inherit ITEM;
    inherit COMBINED;

// ��������ȡװ����ɫ����ɫ
int get_item_color() { return 0; }

// ��������������
//  int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 322; }

// ���������촦��
void create()
{
        set_name("֩��˿");
        set_picid_1(4037);
        set_picid_2(4037);
        set_value(225);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��֯���һ��ԭ���ϣ�������Ʒ��"; 
}
