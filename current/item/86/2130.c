
// �Զ����ɣ�/make/equip/86y

inherit NECK;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("�޼�����");
        set_picid_1(8613);
        set_picid_2(8613);
        set_unit("��");

        set_level(130);
        set_value(84750);
        set_max_lasting(8499);
        set("ap", 64);
        set("cp", 65);
        set("spec.??%", 15);
        set("spec.pp", 55);
        set("spec.@%", 28);
        set("spec./%", 15);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�޼�����";
}
