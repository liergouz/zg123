
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("����ϼ��");
        set_picid_1(6678);
        set_picid_2(6678);

        set_level(100);
        set_value(45500);
        set_max_lasting(9699);
        set("dp", 67);
        set("pp", 125);

        setup();

        set_gender(2);
        set_head_code(57);
}

// ��������ȡ����
string get_desc()
{
        return "����ϼ��";
}
