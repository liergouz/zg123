
// �Զ����ɣ�/make/item/make30

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 236; }

// ���������촦��
void create()
{
        set_name("����Ƥë");
        set_picid_1(4106);
        set_picid_2(4106);
        set_unit("��");
        set_value(150);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "����������������֮���"; 
}
