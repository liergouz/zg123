
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("����ϼ��");
        set_picid_1(6682);
        set_picid_2(6682);

        set_level(120);
        set_value(40000);
        set_max_lasting(18699);
        set("dp", 137);
        set("pp", 78);

        setup();

        set_gender(2);
        set_head_code(58);
}

// ��������ȡ����
string get_desc()
{
        return "����ϼ��";
}
