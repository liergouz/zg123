
// �Զ����ɣ�/make/item/make30

inherit ITEM;
    inherit COMBINED;

// ��������ȡװ����ɫ����ɫ
int get_item_color() { return 0; }

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("�����ͷ��");
        set_picid_1(4013);
        set_picid_2(4013);
        set_value(93);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "����ʹ�õ�������������Ʒ��"; 
}
