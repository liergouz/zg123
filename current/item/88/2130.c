
// �Զ����ɣ�/make/equip/88y

inherit BOOTS;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("׷����");
        set_picid_1(8813);
        set_picid_2(8813);
        set_unit("˫");

        set_level(130);
        set_value(28500);
        set_max_lasting(15099);
        set("dp", 35);
        set("pp", 24);
        set("spec.??%", 20);
        set("spec.?%", 15);
        set("spec.c?%", 8);
        set("spec.X@%", 8);
        set("spec./%", 8);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "׷����";
}
