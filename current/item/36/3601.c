
// �Զ����ɣ�/make/item/make36

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("��");
        set_picid_1(3601);
        set_picid_2(3601);
        set_unit("��");
        set_value(50);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "������һ��"; 
}
